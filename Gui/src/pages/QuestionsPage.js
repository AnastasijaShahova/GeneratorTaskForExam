import { Component } from "react";
import { Card } from "../components/Card";

export const QuestionsPage = () => {
    const questions = [
        {
            id: 1,
            name: "Вопрос №1",
            description: "Questions Description",
        },
        {
            id: 2,
            name: "Вопрос №2",
            description: "Questions Description",
        },
        {
            id: 3,
            name: "Вопрос №3",
            description: "Questions Description",
        },
        {
            id: 4,
            name: "Вопрос №4",
            description: "Questions Description",
        },
        {
            id: 5,
            name: "Вопрос №5",
            description: "Questions Description",
        },
    ];

    return (
        <div className="container">
            {questions.map((question) => (
                <Card
                    id={question.id}
                    name={question.name}
                    description={question.description}
                />
            ))}
        </div>
    );
};
