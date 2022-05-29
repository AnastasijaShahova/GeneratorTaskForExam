import CircleChart from "../components/CircleChart";
import "../styles/StatisticPage.scss";

const StatisticPage = () => {
    return (
        <div className="statistic">
            <div className="statistic__info">
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
            </div>
        </div>
    );
};

export default StatisticPage;
