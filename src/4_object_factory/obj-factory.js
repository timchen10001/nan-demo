var addon = require('bindings')('object');

var obj1 = addon('hello 2');
var obj2 = addon('world 5');

console.log(obj1.msg + ' ' + obj2.msg);