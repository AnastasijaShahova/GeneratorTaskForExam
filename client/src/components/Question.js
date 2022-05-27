import "../styles/Question.scss";

const Question = ({ number, text, userAnswers, setUserAnswers, index }) => {
    const handleInput = (e) => {
        const newUserAnswers = [...userAnswers]
        newUserAnswers[index] = e.target.value

        setUserAnswers(newUserAnswers)
    };

    return (
        <div className="question">
            <div className="question__number">
                <h3>Задание {number}.</h3>
            </div>
            <p>{index+1}. {text}</p>
            <input
                placeholder="Введите ответ"
                onChange={handleInput}
                id={index}
            />
        </div>
    );
};

export default Question;
