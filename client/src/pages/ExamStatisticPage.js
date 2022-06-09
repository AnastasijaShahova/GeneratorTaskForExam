import { useNavigate } from "react-router-dom";
import CircleChart from "../components/CircleChart";
import "../styles/StatisticPage.scss"


const ExamStatisticPage = () => {
    const history = useNavigate();

    return (
        <div className="exam_statistic container">
            <div className="pref_page">
                <p onClick={() => history(`/statistic`)}>
                    Вернуться к списку возможностей
                </p>
            </div>

            <div className="title_header">
                <p>Готовность к сдаче экзамена</p>
            </div>
            <CircleChart />
        </div>
    );
};

export default ExamStatisticPage;
