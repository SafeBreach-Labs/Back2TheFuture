# Do not import packages in the main scope, ida runner also import this file.

def init_integrations(is_kill_all=True):
    import integrations.ida_pro
    import core.configurations
    ida_location = core.configurations.get_global().configs.integrations.ida.path_ida
    if is_kill_all:
        integrations.ida_pro.IdaCommunicator.kill_all(ida_location)
