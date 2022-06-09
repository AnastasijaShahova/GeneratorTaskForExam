import { useEffect, useState } from "react";
import { useNavigate } from "react-router-dom";
import { useHttp } from "../hooks/http.hook";
import mockData from "../mockData";
import { getStudentsTableHeadrs } from "../utils";

const GeneralRatingPage = () => {
    const [studentsData, setStudentsData] = useState(
        mockData("students_table"),
    ); // Заглушка mockData('students_table')
    const { request } = useHttp();
    const history = useNavigate();
    const headers = getStudentsTableHeadrs();

    useEffect(() => {
        const getStudentData = async () => {
            try {
                const response = await request("dslkkjfdsl");
                setStudentsData(response);
            } catch (err) {
                console.log("General Page err: ", err);
            }
        };

        getStudentData();
    }, []);

    const renderTableData = () => {
        return studentsData.map((student, index) => {
            const { fio, email, countTasks, percent, rating } = student;
            return (
                <tr key={index}>
                    <td>{fio}</td>
                    <td>{email}</td>
                    <td>{countTasks}</td>
                    <td>{percent}</td>
                    <td>{rating}</td>
                </tr>
            );
        });
    };

    return (
        <div className="general_rating container">
            <div className="pref_page">
                <p onClick={() => history(`/statistic`)}>
                    Вернуться к списку возможностей
                </p>
            </div>
            <div className="title_header">
                <p>Общий рейтинг</p>
            </div>

            <div style={{ width: "90%" }}>
                <table className="students__table">
                    <tbody>
                        <tr>
                            {headers.map((key, index) => (
                                <th key={index}>{key}</th>
                            ))}
                        </tr>
                        {renderTableData()}
                    </tbody>
                </table>
            </div>
        </div>
    );
};

export default GeneralRatingPage;
