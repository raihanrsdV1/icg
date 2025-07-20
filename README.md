# One-Pass C++ Compiler: Project Overview

## Introduction

This project implements a one-pass compiler for a subset of C++ using ANTLR for parsing and C++ for code generation. The compiler reads source code, parses it using a custom grammar (`C2105046Parser.g4`), and generates assembly-like code in a single pass. It efficiently handles functions, arrays, logical expressions, short-circuit evaluation, and applies peephole optimizations for improved performance.

---

## Grammar Rules Explained

The grammar file `C2105046Parser.g4` defines the syntax and parsing rules for the compiler. Each rule corresponds to a language construct and is associated with semantic actions for code generation.

### 1. **Program Structure**

- **program**: Entry point, parses the entire source file.
- **declaration_list**: Handles global and local variable declarations.
- **parameter_list**: Parses function parameters, supports type and array information.

### 2. **Expressions**

- **expression**: Handles arithmetic, logical, and relational expressions.
- **logical_expression**: Implements short-circuit evaluation for `&&` and `||`.
- **factor**: Handles constants, variables, function calls, and array accesses.

### 3. **Statements**

- **statement**: Parses assignment, function calls, control flow (`if`, `while`, `for`), and return statements.
- **compound_statement**: Supports nested blocks and scope management.

### 4. **Functions**

- **function_declaration**: Parses function headers and bodies, manages parameter passing and return values.
- **function_call**: Handles invocation, argument evaluation, and stack management.

### 5. **Arrays**

- **array_declaration**: Supports multi-dimensional arrays, type checking, and memory allocation.
- **array_access**: Generates code for index calculation and value retrieval.

---

## One-Pass Compilation Strategy

The compiler uses a single traversal of the source code to perform parsing, semantic analysis, and code generation. This is achieved by embedding C++ actions directly in the grammar rules, allowing immediate code emission as constructs are recognized.

### **Advantages:**
- Fast compilation.
- Immediate error detection.
- Simplified code generation logic.

---

## Code Generation: PUSH and POP

### **Why PUSH/POP?**

- **PUSH**: Used to place values (constants, variables, results of expressions) onto the evaluation stack.
- **POP**: Removes values from the stack, typically after assignment or function return.

This stack-based approach simplifies expression evaluation, function calls, and parameter passing, mirroring the behavior of real-world assembly and virtual machines.

### **Efficient Handling:**

- **Expressions**: Each operand is pushed; operators pop operands, compute, and push results.
- **Function Calls**: Arguments are pushed before the call; return values are popped after.
- **Arrays**: Index calculations push computed addresses; values are pushed/popped as needed.

---

## Advanced Features

### **Functions**

- Parameters are handled via the stack, supporting both value and reference passing.
- Return values are managed by pushing onto the stack before returning.
- Local scopes are managed using a symbol table and scope stack.

### **Arrays**

- Declaration rules allocate contiguous memory.
- Access rules compute addresses using base and index, supporting multi-dimensional arrays.

### **Logical Expressions & Short-Circuit Evaluation**

- Logical operators (`&&`, `||`) are implemented with conditional jumps.
- Short-circuiting is achieved by generating code that skips evaluation of the second operand if the first determines the result.

### **Declaration and Parameter Lists**

- **declaration_list**: Iterates through declarations, updating the symbol table and emitting allocation code.
- **parameter_list**: Parses types and names, updates function signature, and manages stack offsets for parameters.

---

## Peephole Optimization

After code generation, the compiler applies peephole optimization to the output assembly. This is implemented in the `optimize` function in `Ctester.cpp`.

### **Optimization Techniques:**

- **Redundant Instruction Removal**: Eliminates unnecessary PUSH/POP pairs.
- **Constant Folding**: Computes constant expressions at compile time.
- **Jump Simplification**: Merges consecutive jumps and removes unreachable code.
- **Dead Code Elimination**: Removes instructions that do not affect program output.

### **How It Works:**

- The optimizer scans the generated code for patterns (e.g., `PUSH x; POP x`) and replaces or removes them.
- It also looks for opportunities to combine instructions, reducing code size and improving execution speed.

---

## Rule-by-Rule Code Generation Details

### **Example: factor**
- **Purpose**: Handles floating-point constants.
- **Action**: Logs the event, sets type info, and emits a PUSH instruction for the constant.

### **Declaration List Handling**

- Iterates through each declaration, updating the symbol table and emitting code for memory allocation.
- Ensures correct scoping and type information.

---

## Short-Circuit Code Generation for Boolean Expressions

Boolean expressions are handled using short-circuit evaluation, which is crucial for efficient assembly code and correct logic. In 8086 assembly, this is achieved by generating conditional jump instructions that skip unnecessary evaluations:

- For `&&` (AND): If the first operand is false, the second is not evaluated; a jump is made to the false label.
- For `||` (OR): If the first operand is true, the second is not evaluated; a jump is made to the true label.

**Implementation Steps:**
1. Each logical expression is assigned unique true/false labels.
2. The code for the first operand is generated, followed by a conditional jump to the appropriate label based on its value.
3. The second operand is only evaluated if needed.
4. This approach avoids unnecessary computation and matches C/C++ semantics.

**Example:**
```asm
; C code: if (a && b)
MOV AX, [a]
CMP AX, 0
JE FALSE_LABEL
MOV AX, [b]
CMP AX, 0
JE FALSE_LABEL
JMP TRUE_LABEL
FALSE_LABEL:
; ...
TRUE_LABEL:
; ...
```

---

## Optimization Steps and Techniques

After generating the initial assembly code, several peephole optimizations are applied to improve performance and reduce code size. These optimizations are implemented in the `optimize` function in `Ctester.cpp` and include:

### 1. **Redundant MOV Removal**
Removes unnecessary MOV instructions, such as:
```
MOV AX, a
MOV a, AX ; ← redundant, can be removed
```
The optimizer scans for consecutive MOVs involving the same register and memory location and eliminates the second if it does not affect program state.

### 2. **Redundant PUSH/POP Removal**
Eliminates consecutive PUSH and POP of the same register/address:
```
PUSH AX
POP AX ; ← redundant, can be removed
```
This reduces stack operations and speeds up execution.

### 3. **Redundant Operations**
Removes operations that do not change the value:
```
ADD AX, 0
MUL AX, 1
```
These are detected and removed as they have no effect on the register value.

### 4. **Redundant Label Removal**
Consecutive unused labels are merged or removed:
```
L3:
L4:
L5: ; Any two of the three can be removed
```
The optimizer ensures only necessary labels remain, improving code readability and reducing jumps.

---

## Tackling Each Requirement

### 1. **Grammar Consistency**
The same grammar from assignment 3 is used for both syntax and semantic analysis, ensuring compatibility and correctness.

### 2. **One-Pass and Two-Pass Compilation**
The compiler is designed for one-pass code generation, emitting assembly as parsing occurs. For two-pass, the parse tree is built first, then traversed to generate code. Both methods are supported, but one-pass is preferred for efficiency.

### 3. **8086 Assembly Generation**
All generated code is valid 8086 assembly, tested on EMU8086. Local variables are managed via the stack, and no data segment variables are used for locals.

### 4. **Stack-Based Local Variables**
Local variables are allocated and accessed through stack operations (PUSH, POP, MOV with BP offsets), ensuring proper function scope and lifetime.

### 5. **Short-Circuit Boolean Code**
Boolean expressions use conditional jumps for short-circuiting, as described above, ensuring efficient and correct logic.

### 6. **Function Parameters and Return Values**
All function parameters are passed via the stack. Return values use a register (typically AX) for efficiency and convention.

### 7. **Source Line Annotation**
Each block of generated assembly is annotated with the corresponding source line number as a comment, aiding debugging and traceability.

### 8. **println(ID) Procedure**
A dedicated procedure for `println(ID)` is written in assembly. The compiler emits a call to this procedure whenever a rule with `println` is reduced.

### 9. **No Floating Point Operations**
The compiler does not generate code for floating point operations, as per requirements.

### 10. **Bonus: Recursive Functions**
Recursive functions are supported by managing activation records on the stack, ensuring correct parameter passing, local variable allocation, and return address handling.

---

## Example: Annotated Assembly Output

```asm
; Line 12: int a = 5;
MOV AX, 5
MOV [BP-2], AX

; Line 15: if (a && b)
MOV AX, [BP-2]
CMP AX, 0
JE FALSE_LABEL_15
MOV AX, [BP-4]
CMP AX, 0
JE FALSE_LABEL_15
JMP TRUE_LABEL_15
FALSE_LABEL_15:
; ...
TRUE_LABEL_15:
; ...
```

---

## Summary

This compiler project demonstrates efficient one-pass code generation for 8086 assembly, advanced handling of functions, arrays, and logical expressions, and robust peephole optimization. All requirements are met, including stack-based variable management, short-circuit boolean logic, annotated output, and support for recursive functions.

### **Parameter List Handling**

- Parses each parameter, determines type and array status, and updates the function’s symbol table entry.
- Manages stack offsets for efficient access during function execution.

---

## Nitpicky Details & Best Practices

- **Symbol Table**: Used for scope management, type checking, and variable/function lookup.
- **Error Handling**: Immediate error reporting during parsing and code generation.
- **Scope Management**: Enter/exit scopes on block entry/exit, ensuring correct variable lifetimes.
- **Type Checking**: Enforced during parsing, preventing invalid operations.

---

## How to Build and Run

1. **Generate Parser/Lexer**:  
   Use ANTLR to generate C++ parser and lexer from `C2105046Parser.g4` and `C2105046Lexer.g4`.

2. **Compile Source**:  
   Use the provided scripts (`run-script.sh`, `clean-script.sh`) to build the compiler.

3. **Run Compiler**:  
   Pass a C++ source file from the `input/` directory to the compiler. Output will be generated in `imp_stuffs/`.

---

## Conclusion

This project demonstrates a robust one-pass compiler for C++, handling complex features like functions, arrays, and logical expressions with efficient code generation and optimization. The use of ANTLR for parsing and C++ for code emission provides flexibility and performance, while peephole optimization ensures the generated code is compact and efficient.

---

## References

- [ANTLR Documentation](https://www.antlr.org/)
- [C++ Language Reference](https://en.cppreference.com/)
- Project source files:  
  - `C2105046Parser.g4` (grammar and rules)  
  - `Ctester.cpp` (optimization logic)  
  - `2105046_main.cpp` (main compiler logic)
