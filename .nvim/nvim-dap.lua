local dap = require('dap')

dap.adapters.lldb = {
  type = 'executable',
  command = '/usr/bin/lldb-vscode', -- adjust as needed, must be absolute path
  name = 'lldb'
}

dap.configurations.c = {
  {
    name = 'klist_test',
    type = 'lldb',
    request = 'launch',
    program = "klist_test",
    cwd = '${workspaceFolder}',
    stopOnEntry = false,
    args = {},
  },
}
