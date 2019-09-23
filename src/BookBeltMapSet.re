// https://dev.to/johnridesabike/bucklescript-belt-s-map-and-set-customizing-key-types-2cel

type book = {
  title: string,
  author: string,
};

type star =
  | One
  | Two
  | Three
  | Four
  | Five;

type review = {
  name: string,
  date: float,
  text: string,
  rating: star,
};
module BookCompare =
  Belt.Id.MakeComparable({
    type t = book;
    let cmp = (a, b) =>
      switch (compare(a.title, b.title)) {
      | 0 => compare(a.author, b.author)
      | x => x
      };
  });
let reviews = Belt.Map.make(~id=(module BookCompare));

let book = {title: "Incarnadine", author: "Szybist, Mary"};
let review = {
  name: "John",
  rating: Five,
  text: "Great collection! I liked the poem *Invitation*.",
  date: 1568898720165.0,
};
let reviews = Belt.Map.set(reviews, book, [review]);
reviews->Js.log2("reviews",_);