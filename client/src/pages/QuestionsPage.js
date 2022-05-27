import { useContext, useEffect, useState } from "react";
import ResultModal from "../components/ResultModal";
import { AuthContext } from "../context/AuthContext";
import { useHttp } from "../hooks/http.hook";
import { useNavigate } from "react-router-dom";
import "../styles/QuestionsPage.scss";
import mockData from "../mockData";
import Question from "../components/Question";

const QuestionsPage = () => {
    // const [countTrueAnswer, setCountTrueAnswer] = useState("0")
    // const [countFalseAnswer, setCountFalseAnswer] = useState("0")
    // const [active, setActive] = useState(false)

    // const auth = useContext(AuthContext);
    // const { request } = useHttp(auth.setModal, auth.setMessage);

    // const [trueAnswers, setTrueAnswers] = useState([]);

    // const [answers, setAnswers] = useState([]);
    // let search = window.location.search;
    // const topicId = parseInt(search.replace(/\D+/g,""));
    // useEffect(async () => {
    //     try {
    //         const data = await request(`http://127.0.0.1:3001/questions?topicId=${topicId}`);
    //         setTrueAnswers(data);
    //     } catch(err) {
    //         console.log("Question error ", err)
    //     }
    // }, [])

    // const calculateAnswers = (userAnswers) => {
    //     let countTrueAns = 0, countFalseAns = 0
    //     userAnswers.forEach(userAnswer => {
    //         const trueAns = trueAnswers.find(trueAnswer => trueAnswer.answer === parseInt(userAnswer.answer))
    //         trueAns ? countTrueAns += 1 : countFalseAns += 1
    //     })
    //     setCountTrueAnswer(countTrueAns)
    //     setCountFalseAnswer(countFalseAns)
    // }

    // const sendResults = () => {
    //     calculateAnswers(answers)
    //     setActive(true)
    // };

    // const handleInput = (e) => {
    //     const { id, value } = e.target;

    //     const findAnswer = answers.find(
    //         (answer) => answer.answerId === id,
    //     );

    //     if (findAnswer) {
    //         findAnswer.answer = value;
    //         // setAnswers(findAnswer)
    //     } else {
    //         answers.push({ answerId: id, answer: value });
    //         setAnswers(answers);
    //     }
    // };

    const questions = mockData("questions"); //Заглушка
    // const [questions, setQuestions] = useState([]);
    const [userAnswers, setUserAnswers] = useState([]);

    const history = useNavigate();

    const clickHandler = (e) => {
        e.preventDefault();
        history("/variants");
    };

    console.log(userAnswers);

    return (
        <div className="questions">
            <div className="questions__variants_page">
                <p onClick={clickHandler}>Вернуться к списку заданий</p>
            </div>
            {questions.map((question, index) => (
                <Question
                    text={question.text}
                    number={question.number}
                    userAnswers={userAnswers}
                    setUserAnswers={setUserAnswers}
                    index={index}
                />
            ))}
            <button>Отправить результаты</button>

            {/* <div className="questions__sendAns">
                <button onClick={sendResults}>Отправить</button>
            </div>

            <ResultModal active={active} setActive={setActive} trueAnswers={countTrueAnswer} falseAnswers={countFalseAnswer} countAll={trueAnswers.length}/> */} */}
        </div>
    );
};

export default QuestionsPage;
