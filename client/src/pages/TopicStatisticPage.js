import { useEffect, useState } from "react";
import { useNavigate } from "react-router-dom";
import { useHttp } from "../hooks/http.hook";
import mockData from "../mockData";
import "../styles/StatisticPage.scss"

const TopicStatistikPage = () => {
    const [topicData, setTopicData] = useState(mockData("variants"));
    const history = useNavigate();

    const { request } = useHttp();

    useEffect(() => {
        const getUserTopicStatisticData = async () => {
            try {
                const response = await request("/get-topic-statistic?userId=1");
                setTopicData(response);
            } catch (err) {
                console.log("Topic Statistic err: ", err);
            }
        };
        getUserTopicStatisticData();
    }, []);

    return (
        <div className="topic_statistic container">
            <div className="pref_page">
                <p onClick={() => history(`/statistic`)}>
                    Вернуться к списку возможностей
                </p>
            </div>
            <div className="title_header">
                <p>Статистика по темам</p>
            </div>
            <p>
                Указан процент неверных ответов, которые вы давали на вопросы по
                теме.
            </p>

            <div className="topic_statistic__list">
                {topicData.map((topic, index) => (
                    <div key={index} className="topic_statistic__list__item">
                        <p style={{"marginLeft": "20px"}}>{topic.number}. {topic.text}</p>
                        <p style={{"marginRight": "20px"}}>{topic.percent} %</p>
                    </div>
                ))}
            </div>

            <p className="topic_statistic__bottom_text">
                Нажмите на строчку с интересующей вас темой для перехода к ней .
            </p>
        </div>
    );
};

export default TopicStatistikPage;
