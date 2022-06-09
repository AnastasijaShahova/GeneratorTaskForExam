import { useEffect, useState } from "react";
import { useNavigate } from "react-router-dom";
import { useHttp } from "../hooks/http.hook";
import mockData from "../mockData";
import "../styles/Teacher.scss";

const StudentProfilePage = () => {
    const [selectValue, setSelectValue] = useState(null);
    const [userNames, setUserNames] = useState(mockData("get_students_names")); //Заглушка mockData('get_students_names')
    const [userTopicData, setUserTopicData] = useState(mockData("variants")); // Заглушка mockData("variants")
    const { request } = useHttp();
    const history = useNavigate();

    useEffect(() => {
        const getUserNames = async () => {
            try {
                const response = await request("url");
                setUserNames(response);
            } catch (err) {
                console.log("StudentProfilePage err: ", err);
            }
        };

        getUserNames();
    }, []);

    useEffect(() => {
        const getUserTopicData = async () => {
            try {
                const response = await request("url");
                setUserTopicData(response);
            } catch (err) {
                console.log("StudentProfilePage err: ", err);
            }
        };

        getUserTopicData();
    }, [selectValue]);

    const selectHandler = (e) => {
        setSelectValue(e.target.value);
    };

    return (
        <div className="student_profile container">
            <div className="pref_page">
                <p onClick={() => history(`/teacher`)}>
                    Вернуться к списку возможностей
                </p>
            </div>

            <div className="title_header">
                <p>Индивидуальный профиль знаний учащегося</p>
            </div>
            <p>Выберите ученика, по которому хотите посомтреть статистику</p>

            <select className="" value={selectValue} onChange={selectHandler}>
                {userNames.map((name, index) => (
                    <option key={index}>{name}</option>
                ))}
            </select>
            {userTopicData && (
                <div className="student_profile__list">
                    {userTopicData.map((topic, index) => (
                        <div
                            key={index}
                            className="student_profile__list__item"
                        >
                            <p style={{ marginLeft: "20px" }}>
                                {topic.number}. {topic.text}
                            </p>
                            <p style={{ marginRight: "20px" }}>
                                {topic.percent} %
                            </p>
                        </div>
                    ))}
                    <p style={{ marginTop: "10px" }}>
                        Указан процент неверных ответов, которые вы давали на
                        вопросы по теме.
                    </p>
                </div>
            )}
        </div>
    );
};

export default StudentProfilePage;
