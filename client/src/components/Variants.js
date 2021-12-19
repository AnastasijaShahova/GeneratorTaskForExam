import { useContext, useEffect, useState } from "react";
import { AuthContext } from "../context/AuthContext";
import { useHttp } from "../hooks/http.hook";
import "../styles/Variants.scss";

const Variants = () => {
    const mock_topics = [
        { id: 1, name: "Анализ информационных моделей" },
        { id: 2, name: "Построение таблиц истинности" },
    ];

    const auth = useContext(AuthContext);

    const [topics, setTopics] = useState(mock_topics);
    const { request } = useHttp(auth.setModal);

    // useEffect(() => {
    //     try {
    //         const data = await request("http://127.0.0.1:3001/topics");
    //         setTopics(data);
    //     } catch (err) {
    //         console.log("Get variants error", err);
    //     }
    // }, []);

    return (
        <div className="variants">
            <h5>Конструктор вариантов по типам и темам</h5>
            <div className="variants__list">
                {topics.map((topic) => (
                    <p>
                        {topic.id}.{" "}
                        <a href={`variants/variant?variant_id=${topic.id}`}>
                            {topic.name}
                        </a>
                    </p>
                ))}
            </div>
        </div>
    );
};

export default Variants;
