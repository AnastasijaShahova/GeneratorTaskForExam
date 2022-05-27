import React, { useContext } from "react";
import { useNavigate } from "react-router-dom";
import "../styles/Navbar.scss";
import { AuthContext } from "../context/AuthContext";

const Navbar = ({ userName, userRole }) => {
    const history = useNavigate();
    const { logout } = useContext(AuthContext);

    const statisticHandler = (e) => {
        e.preventDefault();
        history("/statistic");
    };

    const logoutHandler = (e) => {
        e.preventDefault();
        logout();
        history("/login");
    };

    return (
        <div className="navbar">
            <div className="navbar__title">
                <h1>Task Generator</h1>
            </div>
            <div className="navbar__info">
                <div className="navbar__info__user">
                    <div className="navbar__info__user__icon">
                        <i className="material-icons">account_circle</i>
                    </div>
                    <div className="navbar__info__user__name">
                        <p style={{ fontSize: "20px" }}>{userName}</p>
                        <p>{userRole}</p>
                    </div>
                </div>
                <p onClick={statisticHandler}>Статистика</p>
                <p className="logout" onClick={logoutHandler}>Выйти</p>
            </div>
        </div>
    );
};

export default Navbar;
