import React from "react";
import "../styles/Modal.scss";

const ResultModal = ({
    active,
    setActive,
    trueAnswers,
    falseAnswers,
    countAllAnswers,
}) => {
    return (
        <div className={active ? "modal active" : "modal"}>
            <div
                className="modal__content"
                onClick={(e) => e.stopPropagation()}
            >
                <p>Количество правильных ответов: {trueAnswers}</p>
                <p>Количество неправильных ответов: {falseAnswers}</p>
                <p style={{ marginTop: "10px" }}>
                    Всего заданий: {countAllAnswers}
                </p>
                
                <div className="modal__content__button">
                    <button onClick={() => setActive(false)}>Закрыть</button>
                </div>
            </div>
        </div>
    );
};

export default ResultModal;
