var addon = require('bindings')('callback');

addon(function(msg) {
    console.log(msg); 
});