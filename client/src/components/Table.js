import { useEffect, useState } from "react";
import { useHttp } from "../hooks/http.hook";
import mockData from "../mockData";
import "../styles/Table.scss";
import { getStudentsTableHeadrs } from "../utils";

const Table = () => {
    const [students, setStudents] = useState(mockData("students_table")); //Заглушка mockData['table']

    // const { request } = useHttp();

    // useEffect(() => {
    //     const getStudents = async () => {
    //         try {
    //             const response = await request("/getStudents");
    //             setStudents(response);
    //         } catch (err) {
    //             console.log("GeneralRatingPage err: ", err);
    //         }
    //     };

    //     getStudents()
    // }, []);

    const renderTableData = () => {
        return students
            ? students.map((student, index) => {
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
              })
            : null;
    };

    const renderTableHeader = () => {
        let headers = getStudentsTableHeadrs();
        return headers.map((key, index) => {
            return <th key={index}>{key}</th>;
        });
    };

    console.log(students);

    return (
        <div style={{ width: "90%" }}>
            <table className="students">
                <tbody>
                    <tr>{renderTableHeader()}</tr>
                    {renderTableData()}
                </tbody>
            </table>
        </div>
    );
};

export default Table;
