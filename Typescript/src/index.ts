// TypeScript Learning - Basic Types

// 1. Basic Types
const name: string = "Akrom";
const age: number = 25;
const isStudent: boolean = true;

console.log(`Hello ${name}, age ${age}, student: ${isStudent}`);

// 2. Arrays
const numbers: number[] = [1, 2, 3, 4, 5];
const strings: Array<string> = ["a", "b", "c"];

console.log("Numbers:", numbers);
console.log("Strings:", strings);

// 3. Union Types
let value: string | number;
value = "hello";
console.log("Value as string:", value);
value = 42;
console.log("Value as number:", value);

// 4. Interface
interface User {
  name: string;
  age: number;
  email?: string; // optional
}

const user: User = {
  name: "Akrom",
  age: 25,
  email: "akrom@example.com",
};

console.log("User:", user);

// 5. Function dengan Type
function greet(person: User): string {
  return `Hello ${person.name}!`;
}

console.log(greet(user));

// 6. Class
class Person {
  name: string;
  age: number;

  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }

  describe(): string {
    return `${this.name} is ${this.age} years old`;
  }
}

const person = new Person("Akrom", 25);
console.log(person.describe());
