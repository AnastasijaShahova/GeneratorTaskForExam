import { useNavigate } from "react-router-dom";
import Table from "../components/Table";

const GeneralRatingPage = () => {
    const history = useNavigate();

    return (
        <div className="container">
            <div className="pref_page">
                <p onClick={() => history(`/statistic`)}>
                    Вернуться к списку возможностей
                </p>
            </div>
            <div className="title_header">
                <p>Общий рейтинг</p>
            </div>

            <Table />
        </div>
    );
};

export default GeneralRatingPage;
