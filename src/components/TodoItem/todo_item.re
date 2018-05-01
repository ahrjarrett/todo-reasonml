let toString = ReasonReact.stringToElement;

module TodoItem = {
  let component = ReasonReact.statelessComponent("TodoItem");
  let make = (~todo: todo, ~onToggle, ~clickDelete, _children) => {
    ...component,
    /* I don't understand why _self...is this bc it's stateless? */
    render: _self =>
      <div className="item" onClick=(_e => onToggle())>
        <input
          className="checkbox"
          _type="checkbox"
          checked=(Js.Boolean.to_js_boolean(todo.completed))
        />
        <label> (toString(todo.text)) </label>
        <input
          _type="button"
          className="btn-delete"
          value="x"
          onClick=(_e => clickDelete())
        />
      </div>,
  };
};