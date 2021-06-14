var fib_cpp = require("bindings")("fibonacci")();

var fib_native = (n) =>
  n === 0 || n === 1 ? n : fib_native(n - 2) + fib_native(n - 1);

function compare(n) {
  var cpp_start = performance.now();
  console.log(`fib_cpp for n = ${n} => `, fib_cpp(n));
  var cpp_sec = performance.now() - cpp_start;

  var native_start = performance.now();
  console.log(`fib_native for n = ${n} => `, fib_native(n));
  var native_sec = performance.now() - native_start;

  const ret = {
    "order": n,
    "cpp ms": cpp_sec,
    "node ms": native_sec,
  };

  console.log(ret);

  return ret;
}


const records = [];
for (let i = 2; i <= 45; i++) {
  records.push(compare(i));
}

console.log(records);