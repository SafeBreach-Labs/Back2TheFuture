#usage example



#python createIdlProject.py
    #-m "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe" 
    #-s "" -e endpoint_mapping.txt
    #-i "idls"
    #-o idl_projects2 
    #-r "one_idl_unordered_ALL.txt"
	
	
def init_arg_parser():
    parser = argparse.ArgumentParser(description='Print MSRC patched vulnerabilities')
    parser.add_argument('--source_path', '-s', action='store', help="Path to the visual studio projects source", type=str)
    parser.add_argument('--msbuild_path', '-m', action='store', help="msbbuild.exe path", type=str)
    parser.add_argument('--endpoint_mapping_file', '-e', action='store', help="path to the endpoint mapping taken from #https://gist.github.com/enigma0x3/2e549345e7f0ac88fad130e2444bb702")
    parser.add_argument('--input_dirname', '-i', action='store', help="input dir name (not path) where the order idls will be written to and read from")
    parser.add_argument('--output_dir', '-o', action='store', help="output dir for projects and final compiled exectuables")
    #only for first run
    parser.add_argument('--rpcview_file', '-r', action='store', help="rpcview output file as an input - for fixing the order of the idl file first")
    'one_idl_unordered3.txt'
    return parser.parse_args()
