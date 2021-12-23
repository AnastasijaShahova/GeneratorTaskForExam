import { useContext, useEffect, useState } from "react";
import { AuthContext } from "../context/AuthContext";
import { useHttp } from "../hooks/http.hook";
import "../styles/Variants.scss";
import {useNavigate} from "react-router-dom";

const Variants = () => {

    // const mock_topics = [{id: 1, number: 7, text: "lsdk;kfs;"}]

    const auth = useContext(AuthContext);

    const [topics, setTopics] = useState([]);
    const { request } = useHttp(auth.setModal);

    const history = useNavigate()
    useEffect(async () => {
        try {
            const data = await request("http://127.0.0.1:3001/topics?page=2");
            setTopics(data);
        } catch (err) {
            console.log("Get variants error", err);
        }
    }, []);
    const handleLink = (number) => {
        history(`/variants/variant?variant_id=${number}`)
    }

    return (
        <div className="variants">
            <h4>Конструктор вариантов по темам</h4>
            <div className="variants__list">
                {topics.map((topic,index) => (
                     <p id={index}>
                        {topic.id}.{" "}
                        <a onClick={()=>handleLink(topic.number)}>
                            {topic.text}
                        </a>
                    </p>
                ))}
            </div>
        </div>
    );
};

export default Variants;
