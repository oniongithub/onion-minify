# Supported Languages

This repository contains implementations of the `minifyLua` and `unminifyLua` functions in the following languages:

- Lua
- JavaScript
- Rust
- C++
- Java

Each language has its own subdirectory containing the source code for the functions.

To test it out visit https://oniongithub.github.io/onion-minify-site/

## minifyLua

The `minifyLua` function takes a string containing Lua code as an argument and returns a minified version of the code. The function removes unnecessary whitespace and comments from the code to make it more compact.

Here's an example of how to use the `minifyLua` function:

```javascript
let code = `
    local x = 1
    local y = 2
    local z = x + y
`

let minifiedCode = minifyLua(code)
console.log(minifiedCode)
```
This will output the following minified code:

```
local x=1 local y=2 local z=x+y
```

## unminifyLua

The `unminifyLua` function takes a string containing minified Lua code as an argument and returns a more readable version of the code. The function adds line breaks and spaces to the code to make it easier to read.

Here’s an example of how to use the `unminifyLua` function:

```javascript
let minifiedCode = `local x=1 local y=2 local z=x+y`

let formattedCode = unminifyLua(minifiedCode)
console.log(formattedCode)
```

This will output the following formatted code:

```javascript
local x = 1 
local y = 2 
local z = x + y
```
Keep in mind that the unminifyLua function only adds line breaks and spaces to the code. It does not restore the original indentation or comments.
