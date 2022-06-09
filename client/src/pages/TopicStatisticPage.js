import { useNavigate } from "react-router-dom";

const TopicStatistikPage = () => {
    const history = useNavigate();

    return (
        <div className="container">
            <div className="pref_page">
                <p onClick={() => history(`/statistic`)}>
                    Вернуться к списку возможностей
                </p>
            </div>
        </div>
    );
};

export default TopicStatistikPage;
