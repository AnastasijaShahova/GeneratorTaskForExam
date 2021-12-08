export const Variant = (props) => {
    return (
        <li className="collection-item avatar">
            <i className="material-icons circle green">insert_chart</i>
            <span className="title">{props.name}</span>
            <a
                href={"/variants/" + props.id}
                className="waves-effect waves-light btn-large secondary-content"
            >
                Начать решение
            </a>
        </li>
    );
};
