import { useContext, useEffect, useState } from "react";
import ResultModal from "../components/ResultModal";
import { AuthContext } from "../context/AuthContext";
import { useHttp } from "../hooks/http.hook";
import { useNavigate } from "react-router-dom";
import "../styles/QuestionsPage.scss";
import mockData from "../mockData";
import Question from "../components/Question";

const QuestionsPage = () => {
    const [questions, setQuestions] = useState([]); //Заглушка mockData("questions")

    const [answers, setAnswers] = useState([]); //Заглушка mockData("answers")
    const [modalActive, setModalActive] = useState(false);
    const [userAnswers, setUserAnswers] = useState([]);

    const [countTrueAnswers, setCountTrueAnswers] = useState(0);
    const [countFalseAnswers, setCountFalseAnswers] = useState(0);

    const history = useNavigate();

    const { request } = useHttp();

    let search = window.location.search;
    const topicId = parseInt(search.replace(/\D+/g, ""));

    const URL =
        process.env.REACT_APP_SERVER_URL + `/questions?topicId=${topicId}`;

    useEffect(() => {
        const fetchAnswers = async () => {
            try {
                const data = await request(URL);
                setAnswers(data);
            } catch (e) {
                console.log("Question Page error: ", e);
            }
        };
        fetchAnswers();
    }, []);

    const clickHandler = (e) => {
        e.preventDefault();
        history("/variants");
    };

    const sendResults = () => {
        calculateAnswers(answers);
        setModalActive(true);
    };

    const calculateAnswers = (answers) => {
        let countTrueAnswers = 0,
            countFalseAnswers = 0;
        for (let i = 0; i < answers.length; i += 1) {
            const currentInput = document.getElementById(i);
            if (answers[i] === userAnswers[i]) {
                countTrueAnswers += 1;
                currentInput.style.border = "2px solid green";
            } else {
                countFalseAnswers += 1;
                currentInput.style.border = "2px solid red";
            }
        }
        setCountTrueAnswers(countTrueAnswers);
        setCountFalseAnswers(countFalseAnswers);
    };

    return (
        <div className="questions">
            <div className="questions__variants_page">
                <p onClick={clickHandler}>Вернуться к списку заданий</p>
            </div>
            {questions.map((question, index) => (
                <Question
                    question={question}
                    userAnswers={userAnswers}
                    setUserAnswers={setUserAnswers}
                    index={index}
                />
            ))}
            <button onClick={sendResults}>Отправить результаты</button>

            <ResultModal
                active={modalActive}
                setActive={setModalActive}
                countAllAnswers={questions.length}
                trueAnswers={countTrueAnswers}
                falseAnswers={countFalseAnswers}
            />
        </div>
    );
};

export default QuestionsPage;
