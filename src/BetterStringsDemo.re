// This forces the piped param which would go in first position into `_` position
"ReasonReact"->Js.String.includes("Reason", _)->Js.log;
// Returns false, i presume because there is nothing in the second arg.
"ReasonReact"->Js.String.includes("Reason")->Js.log;
// Here, the piped in string would be in the first position
"ReasonReact"->Js.String2.includes("Reason")->Js.log;

module BetterString = {
  [@bs.send]
  external includes: (string, ~searchString: string) => bool = "includes";
};

"ReasonReact"->BetterString.includes(~searchString="Reason")->Js.log;
