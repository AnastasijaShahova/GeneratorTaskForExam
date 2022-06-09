import { useEffect, useState } from "react";
import { useNavigate } from "react-router-dom";
import { useHttp } from "../hooks/http.hook";
import mockData from "../mockData";
import { getJournalTableHeaders } from "../utils";
import "../styles/Teacher.scss";

const JournalPage = () => {
    const [jornalData, setJournalData] = useState(mockData("journal_table")); //Заглушка mockData('journal_table')
    const history = useNavigate();
    const { request } = useHttp();
    const headers = getJournalTableHeaders();

    useEffect(() => {
        const getJournalData = async () => {
            try {
                const response = await request("dsklfksd");
                setJournalData(response);
            } catch (err) {
                console.log("JournalPage err: ", err);
            }
        };

        getJournalData();
    }, []);

    const renderTableData = () => {
        return jornalData.map((item, index) => {
            const { fio, email, ready } = item;
            let style
            if (ready) {
                style={"backgroundColor": "green"}
            } else if (ready === false) {
                style={"backgroundColor": "red"}
            }
            return (
                <tr key={index}>
                    <td>{fio}</td>
                    <td>{email}</td>
                    <td>
                        <span className="circle" style={style}></span>
                    </td>
                </tr>
            );
        });
    };

    return (
        <div className="journal container">
            <div className="pref_page">
                <p onClick={() => history(`/teacher`)}>
                    Вернуться к списку возможностей
                </p>
            </div>

            <div className="title_header">
                <p>Классный журнал</p>
            </div>

            <div style={{ width: "90%" }}>
                <table className="journal__table">
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

export default JournalPage;
