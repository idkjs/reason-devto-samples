type apples = Js.Dict.t(string);
type oranges = Js.Json.t;

// Js.Dict.fromArray takes the first arg as the key and the second arg as
let apples: apples = Js.Dict.fromArray([|("taste", "sweet")|]);
Js.log2("apples", apples);
let eatFruits = (fruit: Js.Json.t) => Js.log2("Eating fruits", fruit);

// eatFruits(apples);
eatFruits(apples->Obj.magic);