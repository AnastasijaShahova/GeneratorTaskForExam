import { useEffect, useState } from "react";
import { useHttp } from "../hooks/http.hook";
import mockData from "../mockData";
import { useNavigate } from "react-router-dom";
import "../styles/VariantsPage.scss";

const url = process.env.REACT_APP_SERVER_URL + "/topics?page=2";

const VariantsPage = () => {
    const history = useNavigate();

    const [topics, setTopics] = useState([]); // Заглушка mockData("variants")

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

    const clickHandler = (number) => {
        history(`/variants/variant?variant_id=${number}`);
    };

    return (
        <div className="variants">
            <div className="variants__title">
                <h4>Конструктор вариантов по темам</h4>
            </div>
            <div className="variants__list">
                {topics.map((topic) => (
                    <p onClick={() => clickHandler(topic.number)}>
                        {topic.text}
                    </p>
                ))}
            </div>
        </div>
    );
};

export default VariantsPage;
