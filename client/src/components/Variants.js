import { useState } from "react";
import "../styles/Variants.scss";

const Variants = () => {
    const mock_topics = [
        { id: 1, text: "Анализ информационных моделей" },
        { id: 2, text: "Построение таблиц истинности" },
    ];

    const [topics, setTopics] = useState(mock_topics);

    return (
        <div className="variants">
            <h5>Конструктор вариантов по типам и темам</h5>
            <div className="variants__list">
                {topics.map((topic) => (
                    <p>
                        {topic.id}. <a href={`variants/variant?variant_id=${topic.id}`}>{topic.text}</a>
                    </p>
                ))}
            </div>
        </div>
    );
};

export default Variants;
