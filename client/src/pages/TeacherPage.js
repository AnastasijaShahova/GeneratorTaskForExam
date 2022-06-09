import { useNavigate } from "react-router-dom";

const TeacherPage = () => {
    const history = useNavigate();

    return (
        <div className="container">
            <div className="title_header">
                <p>Возможности учителя</p>
            </div>
            <div className="list">
                <p onClick={() => history("/teacher/journal")}>
                    Классный журнал
                </p>
                <p onClick={() => history("/teacher/student-profile")}>
                    Индивидуальный профиль знаний
                </p>
            </div>
        </div>
    );
};

export default TeacherPage;
