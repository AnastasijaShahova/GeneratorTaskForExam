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
        <div className="container">
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
        </div>
    );
};

export default StatisticPage;
