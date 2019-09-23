type apples = Js.Dict.t(string);
type oranges = Js.Json.t;
type fruits = Js.Json.t;
let apples: apples = Js.Dict.fromArray([|("taste", "sweet")|]);

let eatFruits = (fruits: Js.Json.t) => Js.log2("Eating fruits", fruits);

// eatFruits(apples->applesToFruits);
// eatFruits(apples);
// eatFruits(apples->Obj.magic);
// eatFruits(apples);
external applesToFruits: apples => fruits = "%identity";

// eatFruits(apples);
// eatFruits(apples->Obj.magic);
eatFruits(apples->applesToFruits);
