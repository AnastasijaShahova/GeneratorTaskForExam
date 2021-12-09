export const QuestionCard = (props) => {
    console.log(props.answers);
    return (
        <div className="row">
            <div className="col s12">
                <div className="card blue-grey darken-1">
                    <div className="card-content white-text">
                        <span className="card-title center-align">
                            {props.name}
                        </span>
                        <form action="#">
                            {props.answers.map((answer) => (
                                <p>
                                    <label>
                                        <input name="group1" type="radio" />
                                        <span>{answer.name}</span>
                                    </label>
                                </p>
                            ))}
                        </form>
                    </div>
                    
                </div>
            </div>
        </div>
    );
};
