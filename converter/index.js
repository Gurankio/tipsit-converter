switch (process.platform) {
  case "darwin":
    module.exports = require('./bin/darwin-x64-80/converter.node');
    break;

  case "win32":
    module.exports = require('./bin/win32-x64-80/converter.node');
    break;

  default:
    module.exports = require('./build/Release/converter.node');
}
