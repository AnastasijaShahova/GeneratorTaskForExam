import { useContext, useEffect, useState } from "react";
import { AuthContext } from "../context/AuthContext";
import { useHttp } from "../hooks/http.hook";
import "../styles/Variants.scss";

const Variants = () => {

    const auth = useContext(AuthContext);

    const [topics, setTopics] = useState([]);
    const { request } = useHttp(auth.setModal);

    useEffect(async () => {
        try {
            const data = await request("http://127.0.0.1:3001/topics");
            console.log(data)
            setTopics(data);
        } catch (err) {
            console.log("Get variants error", err);
        }
    }, []);

    console.log(topics);
    return (
        <div className="variants">
            <h5>Конструктор вариантов по типам и темам</h5>
            <div className="variants__list">
                {topics.map((topic) => (
                    <p>
                        {topic.id}.{" "}
                        <a href={`variants/variant?variant_id=${topic.number}`}>
                            {topic.text}
                        </a>
                    </p>
                ))}
            </div>
        </div>
    );
};

export default Variants;
