export const Card = (props) => {
    return (
        <div className="row">
            <div className="col s12">
                <div className="card blue-grey darken-1">
                    <div className="card-content white-text">
                        <span className="card-title">{ props.name }</span>
                        <p>{props.description }</p>
                    </div>
                    <div className="card-action">
                        <a href={"/questions/" + props.id}>Начать выполнение</a>
                    </div>
                </div>
            </div>
        </div>
    );
};
