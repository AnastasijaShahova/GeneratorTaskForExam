// import CircleChart from "../components/CircleChart";
import { useNavigate } from "react-router-dom";
import { useContext } from "react";
import { AuthContext } from "../context/AuthContext";
import "../styles/StatisticPage.scss";
import { getStatisticData } from "../utils";

const StatisticPage = () => {
    const history = useNavigate();

    const { role } = useContext(AuthContext);

    const customData = getStatisticData(role);

    return (
        <div className="container statistic">
            <div className="pref_page">
                <p onClick={() => history(`/variants`)}>
                    Вернуться к списку заданий
                </p>
            </div>
            <div className="title_header">
                <p>{customData.header}</p>
            </div>
            <div className="list">
                {customData.list.map((el, index) => (
                    <p onClick={() => history(el.url)} key={index}>
                        {el.text}
                    </p>
                ))}
            </div>
            {/* <div className="statistic__info">
                <div className="statistic__info__text">
                    <div className="statistic__info__text__name">
                        <p>Иванов Иван Иванович, ученик</p>
                    </div>
                    <p>Количество решенных вариантов: 5</p>
                    <p>Количество правильных ответов: 100</p>
                    <p>Место среди других учеников: 10</p>
                    <p>Срендний балл: 4,67</p>
                </div>
                <div className="statistic__info__chart">
                    <CircleChart />
                </div>
            </div> */}
        </div>
    );
};

export default StatisticPage;
