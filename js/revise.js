//map
// Creation
let map = new Map();

// Basic operations
map.set("key1", "value1");
map.set("key2", "value2");
let value = map.get("key1"); // "value1"
let hasKey = map.has("key1"); // true
map.delete("key1"); // remove key
let size = map.size; // 1

// Iteration
for (let [key, value] of map) {
   console.log(key, value);
}

map.forEach((value, key) => {
   console.log(key, value);
});

// string
let s = "javascript";

s.startsWith("java"); // true
s.endsWith("script"); // true
s.replace("java", "type"); // "typescript"
s.repeat(2); // "javascriptjavascript"
s.charAt(4); // "s"
s.charCodeAt(0); // 106 (unicode of 'j')

// basic
let num2 = Number("123"); // 123
let str2 = String(42); // "42"

let num = 234324;
let str = num.toString(); //"234324"


git quickgit quickgit quickgit quickgit quickgit quickgit quickgit quickgit quickgit quick
git quickgit quickgit quickgit quickgit quickgit quick