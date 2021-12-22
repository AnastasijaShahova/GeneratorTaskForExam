import React from "react";
import "../styles/AuthModal.scss";

const ResultModal = ({ active, setActive, trueAnswers, falseAnswers }) => {
    return (
        <div className={active ? "modal active" : "modal"}>
            <div
                className="modal__content"
                onClick={(e) => e.stopPropagation()}
            >
                <p>Количество правильных ответов: {trueAnswers}</p>
                <p>Количество неправильных ответов: {falseAnswers}</p>
                <p>Всего заданий: {trueAnswers + falseAnswers}</p>

                <button onClick={() => setActive(false)}>Закрыть</button>
            </div>
        </div>
    );
};

export default ResultModal;
