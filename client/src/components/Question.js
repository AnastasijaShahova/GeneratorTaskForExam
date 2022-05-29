import "../styles/Question.scss";

const Question = ({ question, userAnswers, setUserAnswers, index }) => {
    const handleInput = (e) => {
        const newUserAnswers = [...userAnswers];
        newUserAnswers[index] = e.target.value;

        setUserAnswers(newUserAnswers);
    };

    return (
        <div className="question">
            <div className="question__number">
                <h3>Задание {question.number}.</h3>
            </div>
            <p>
                {index + 1}. {question.text}
            </p>
            <input
                style={
                    question.inputColor === "red"
                        ? { border: "2px solid red" }
                        : question.inputColor === "green"
                        ? { border: "2px solid green" }
                        : {}
                }
                placeholder="Введите ответ"
                onChange={handleInput}
                id={index}
            />
        </div>
    );
};

export default Question;
