import { useEffect, useState } from "react";
import { useHttp } from "../hooks/http.hook";
import mockData from "../mockData";
import { useNavigate } from "react-router-dom";

const url = process.env.REACT_APP_SERVER_URL + "/topics?page=2";

const VariantsPage = () => {
    const history = useNavigate();

    const [topics, setTopics] = useState(mockData("variants")); // Заглушка mockData("variants")

    const { request } = useHttp();

    useEffect(() => {
        const fetchTopics = async () => {
            try {
                const data = await request(url);
                setTopics(data);
            } catch (e) {
                console.log("Variat error: ", e);
            }
        };
        fetchTopics();
    }, []);


    return (
        <div className="container">
            <div className="title_header">
                <p>Конструктор вариантов по темам</p>
            </div>
            <div className="list">
                {topics.map((topic, index) => (
                    <p
                        key={index}
                        onClick={() =>
                            history(
                                `/variants/variant?variant_id=${topic.number}`,
                            )
                        }
                    >
                        {topic.text}
                    </p>
                ))}
            </div>
        </div>
    );
};

export default VariantsPage;
