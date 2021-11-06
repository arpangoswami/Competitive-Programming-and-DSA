let john = {
    name: 'Hello I am john',
    married: true,
    age: 29,
}
let mary = {
    name: 'Hello I am mary',
    married: true,
    age : 27,
}
let james = {
    name : 'Hello I am james',
    married : false,
    age: 26,
}

let matrimony = new Map();
matrimony.set('john',john);
matrimony.set('mary',mary);
matrimony.set('james',james);

console.log(matrimony.get('mary'))