import { useContext, useEffect, useState } from "react";
import ResultModal from "../components/ResultModal";
import { AuthContext } from "../context/AuthContext";
import { useHttp } from "../hooks/http.hook";
import "../styles/Questions.scss";

const QuestionsPage = () => {
    // const mock_questions = [
    //     {
    //         id: 1,
    //         text: "djnksnfjksnjkdsfsdjfkdshfkhsdhfhsdkhfkkshfkjskdkfjkhdgkfhsdjfhgkjdshkgdhfnfnskfjsjkdfnjksnfjnsknfksnkfnsknfksn",
    //         type: 7,
    //     },
    //     {
    //         id: 2,
    //         text: "djnksnfjksnjkfnskfjsjkdfnjksnfjnsknfksnkfnsknfksn",
    //         type: 7,
    //     },
    //     {
    //         id: 3,
    //         text: "djnksnfjksnjkfnskfjsjkdfnjksnfjnsknfksnkfnsknfksn",
    //         type: 7,
    //     },
    //     {
    //         id: 4,
    //         text: "djnksnfjksnjkfnskfjsjkdfnjksnfjnsknfksnkfnsknfksn",
    //         type: 7,
    //     },
    //     {
    //         id: 5,
    //         text: "djnksnfjksnjkfnskfjsjkdfnjksnfjnsknfksnkfnsknfksn",
    //         type: 7,
    //     },
    // ];

    const [countTrueAnswer, setCountTrueAnswer] = useState("0")
    const [countFalseAnswer, setCountFalseAnswer] = useState("0")
    const [active, setActive] = useState(false)

    const auth = useContext(AuthContext);
    const { request } = useHttp(auth.setModal);

    const [trueAnswers, setTrueAnswers] = useState([]);

    const [answers, setAnswers] = useState([]);
    let search = window.location.search;
    const topicId = parseInt(search.replace(/\D+/g,""));
    useEffect(async () => {
        try {
            const data = await request(`http://127.0.0.1:3001/questions?topicId=${topicId}`);
            setTrueAnswers(data);
        } catch(err) {
            console.log("Question error ", err)
        }
    }, [])

    const calculateAnswers = (userAnswers) => {
        let countTrueAns = 0, countFalseAns = 0
        userAnswers.forEach(userAnswer => {
            const trueAns = trueAnswers.find(trueAnswer => trueAnswer.answer === parseInt(userAnswer.answer))
            trueAns ? countTrueAns += 1 : countFalseAns += 1
        })
        setCountTrueAnswer(countTrueAns)
        setCountFalseAnswer(countFalseAns)
    }

    const sendResults = () => {
        calculateAnswers(answers)
        setActive(true)
    };

    const handleInput = (e) => {
        const { id, value } = e.target;

        const findAnswer = answers.find(
            (answer) => answer.answerId === id,
        );


        if (findAnswer) {
            findAnswer.answer = value;
            // setAnswers(findAnswer)
        } else {
            answers.push({ answerId: id, answer: value });
            setAnswers(answers);
        }
    };

    return (
        <div className="questions">
            {trueAnswers.map((trueAnswer, index) => (
                <div className="questions__item">
                    <h3>Задание {trueAnswer.number}</h3>
                    <div className="questions__item__text">
                        <p>
                            {trueAnswer.answerId}. {trueAnswer.text}
                        </p>
                    </div>

                    <input
                        id={`${trueAnswer.answerId}`}
                        placeholder="Введите ответ"
                        onChange={handleInput}
                    />
                </div>
            ))}

            <div className="questions__sendAns">
                <button onClick={sendResults}>Отправить</button>
            </div>

            <ResultModal active={active} setActive={setActive} trueAnswers={countTrueAnswer} falseAnswers={countFalseAnswer}/>
        </div>
    );
};

export default QuestionsPage;
