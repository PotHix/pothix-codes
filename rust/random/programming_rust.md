Rust Programming
================

Question mark operator does the work of a `match` that returns the
value if valid and the error if invalid. It should not be used in the
`main` function.

Float
* Rust implies no numeric conversion (unlike C/C++)
* If you don't say if it's a f32 or f64 it will choose one. The
  default is f64 if both match

Boolean
* control structures and short-circuit expect booleans, you can't just
  use `if []`
* it's possible to convert to interger via `as`. ex: `true as i32 ==
  1`

Char
* std::char::from_u32 returns an option of a char based on the integer
  form of it. None if it's not valid and some(c) if it's valid

Tuple
* No return type is equivalent to `-> ()`

Pointers
* TODO: Search about dangling pointers
* & for references, Box to allocate in the heap, and * for raw (and
  unsafe) pointers


Array, Vec, Slice
* Indices to one of those types must be a `usize` value

Array
* It's possible to initialize an array of 100 true values with [true;
  100]. You can't add more values to this array or remove its value,
  it's a static array.

Vec
* When using `collect` to create a Vec, it's important to declare the
  type of your vector (e.g. `Vec<i32>`)
* Many of the common know methods are available for Vecs: pop, len,
  remove, etc

Slice
* Slices are always passed by reference because they can have
  arbitrary size
* If you implement a function to work on a sequence of values of the
  same type using slices, it will work for both, arrays and vectors
* `fn print(n: &[f64])` receives a slice of `f64` types. You can call
  this function passing a reference (in this case, a slice) of a
  vector `print(&v)`

String
* `r"this is a raw string"`. Raw strings do not accept backslahs
  escapes. If you want to escape double quotes you can use `r#"raw
  string"#`. The string only ends when he sees the same numbers of
  pound signs after the double quote
* A string length is measured in bytes, not characters
* `let s = "pets".to_string()` converts a &str (reference to a static
  string) into a string allocated in the heap.
* `format!()` macro is just like `println!()` but returns the string
  instead of printing it
* `&str` is just like a slice that can refer to any slice of any
  string, being it a literal (stored in the executable) or a String in
  the heap
* use the right string for what you're doing. `std::path::PathBuf` and
  `&Path` for file names, `Vec<u8>` for binaries, `OsStr` and
  `OsString` for command line arguments and `std::ffi::CString` and
  `&CStr` when interoperating with C libraries thta use
  null-terminated strings

Rust rules
* rust is not like any other language, you can't learn the basics and
  let the difficult parts to learn when you're building stuff. Rust
  forces you to understand most of its concepts just from the
  beginning.
* Fat pointers are pointers that hold more than just the value
  address. A pointer to a string will hold the pointer to the value,
  an integer for the capacity, and an integer for the current length

Ownership
* In C++, people usually use comments to state when an object has the
  ownership of one method and is responsible to free it. What Rust
  does is to make these comments into valid code and compiler checks,
  avoiding dangling pointers.

Move
* Rust moves values from one variable to another, it doesn't reference
  count (like Python) or copy values (like C++) by default
* It's not possible to move an element from a vector because it would
  need extra data on the vector to keep track of what elements were
  moved
* `take()` takes the ownership of some value, keep it
  uninitialized. Something like: `let first_name = composers[0].name.take();`
* Moves are used on values that may take a lot of memory to copy

Copy
* Only files for which a bit-per-bit copy suffices can be `Copy` (trait)
* It's possible to make your own objects (like structs) `Copy` as
  well. You can derive them from `Copy` and `Clone`. Keep in mind that
  if you're using some type that requires the head it will not be
  possible to make it `Copy`

Arc and Rc
* Arc is the *atomic reference counter* while RC is a reference
  counter that is not thread safe. Arc pays the price to be thread
  safe; you should use Rc whenever possible.
  
References in Rust
* The . operator automatically dereferences a reference
* References to references are permitted in Rust. The . operator
  traverses all references. In case there are more than one, it will
  go one by one until it reaches the root value
* At machine level, Rust represents None as nullptr. It's just as
  efficient but safer. If you need to receive something or None, use
  `Option<&T>`
* A reference to a slice is a fat pointer carrying the initial value
  and its length.
* A lifetime is just part of the Rust compiler imagination. In the
  real world, your references are just addresses.
