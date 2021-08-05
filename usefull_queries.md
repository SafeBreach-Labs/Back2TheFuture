    
# useful sql queries 
* PEs with missing symbols (required to have all the functions and not only the changed xrefs)
 `SELECT ranked_obj_pe_name, ranked_obj_kb,count(*) from feature_Function_ChangedFunctions WHERE ranked_obj_function_name like 'sub_%' group by ranked_obj_pe_name, ranked_obj_kb order by count(*) desc;`
 
* count most changed xrefs to functions (by pe or total)
   * Per PE:
    `SELECT reason, ranked_obj_pe_name, COUNT (*) from feature_Function_ChangedXrefs Where type_of_change == "CHANGED" AND reason not like 'sub_%' GROUP BY reason,ranked_obj_pe_name ORDER BY count(*) DESC;`
   * In total: 
   `SELECT reason, count(*) from (
   SELECT reason, ranked_pe_name, ranked_kb, COUNT (*) from feature_Function_ChangedXrefs Where type_of_change == "CHANGED" AND
   reason not like 'sub_%' GROUP BY reason,ranked_pe_name, ranked_kb ORDER BY count(*) DESC
) Group by reason order by count(*) desc;`

* Most frequent changed functions:
    * `SELECT ranked_function_name, ranked_pe_name, count(*) from (
   SELECT ranked_pe_name, ranked_kb,ranked_function_name from feature_Function_ChangedFunctions Where 
   type_of_change == "CHANGED" AND ranked_function_name not like 'sub_%' GROUP BY ranked_function_name,ranked_pe_name, ranked_kb ORDER BY count(*) DESC
)
Group by ranked_function_name, ranked_pe_name
order by count(*) desc;`

* Most (really) changed PE with small changes: 
`SELECT ranked_obj_package_name, ranked_obj_pe_name, count(*) from feature_type_PE_SmallChanges WHERE score > 1 AND score < 25 GROUP BY ranked_obj_package_name, ranked_obj_pe_name ORDER BY count(*) DESC
`

* Function is declared with the same name in multiple PEs 
`select ranked_obj_function_name, count(*) from (
SELECT ranked_obj_function_name, ranked_obj_pe_name from feature_type_Function_ChangedFunctions WHERE ranked_obj_function_name is not NULL AND LENGTH(ranked_obj_function_name) > 1 GROUP BY ranked_obj_function_name, ranked_obj_pe_name ORDER BY count(*) DESC
) group by ranked_obj_function_name order by count(*) DESC
`
* Link between CVE and function features (optional add cve_name like 'CVE-....' to filter specific one)
`SELECT feature_PE_LinkCVEToUpdate.exploit_exploitdb_0, feature_PE_LinkCVEToUpdate.exploit_exploitdb_0, feature_PE_LinkCVEToUpdate.CWE_name, feature_PE_LinkCVEToUpdate.cve_name, feature_PE_LinkCVEToUpdate.vulnerability_type,
feature_PE_LinkCVEToUpdate.score, type_function.ranked_pe_name, type_function.ranked_kb,
type_function.feature_type, type_function.before, type_function.after, type_function.score, 
type_function.reason from feature_PE_LinkCVEToUpdate, type_function where 
feature_PE_LinkCVEToUpdate.ranked_kb == type_function.ranked_kb AND 
feature_PE_LinkCVEToUpdate.ranked_pe_name == type_function.ranked_pe_name AND
type_function.score > 0
Order by cve_name DESC`

* most common changed xrefs
`SELECT reason, ranked_pe_name, before, after, COUNT (*) from feature_Function_ChangedXrefs Where 
Length(reason) > 0 AND reason not like 'sub_%' AND CAST(after as INT)> CAST(before as INT) AND CAST(before as INT) > 0
GROUP BY reason
order by Cast(after as INT) - Cast(before as INT) DESC;`

`select reason, ranked_pe_name, count(*) from feature_Function_ChangedXrefs where type_of_change == "CHANGED" group by reason, ranked_pe_name order by count(*) desc`
* changed constants
`select * from feature_Function_ChangedFunctionConstant where is_good_match == "True" and amount_of_arguments_new == amount_of_arguments_old and amount_of_const_values_new == amount_of_const_values_old
and NOT args_after like "%global%" 
order by ranked_build_date desc`

* sum all scores 



Group by reason
order by count(*) desc;
*  cast (text) field to int/float
`select * from feature_PE_ChangesPes order by cast(score AS INT) desc`

 #Indexing:
create index feature_Function_CfgExtractorXref_from on feature_Function_CfgExtractorXref (ranked_function_name, lower(ranked_pe_name), ranked_package_name, ranked_build_date)

create index feature_Function_CfgExtractorXref_to_external on feature_Function_CfgExtractorXref (imported_function_name, lower(imported_module), ranked_build_date)

create index feature_Function_CfgExtractorXref_to_internal on feature_Function_CfgExtractorXref (reason, address_after,  lower(ranked_pe_name), ranked_package_name, ranked_build_date)

 #Analysis new patch:
1 . `select ranked_pe_name, count(*) from all_features where 
feature_type != "ChangedFunctions" and feature_type != "ChangesPes" and feature_type != "ChangedFunctionConstant" and
score > 0 AND ranked_build_date == "2021-01" group by ranked_pe_name order by count(*) DESC`