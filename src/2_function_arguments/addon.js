var addon = require('bindings')('addon');

console.log('3 + 5 = ', addon.add(3, 5));
console.log('22 + 6 = ', addon.add(22, 6));
console.log('22 + 89 = ', addon.add(22, 89));