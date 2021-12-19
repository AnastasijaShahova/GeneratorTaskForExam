import React from "react";
import { useNavigate } from "react-router-dom";
import "../styles/Navbar.scss";
import { BsPersonSquare } from "react-icons/bs";

const Navbar = ({userName, userRole}) => {
    const history = useNavigate();

    const logoutHandler = (event) => {
        event.preventDefault();
        history("/");
    };

    return (
        <div className="navbar">
            <h1 className="navbar__logo">Task Generator</h1>
            <div className="navbar__profile">
                <div className="navbar__profile__info">
                    <div className="navbar__profile__info__icon">
                        <BsPersonSquare fontSize="3em" />
                    </div>
                    <div className="navbar__profile__info__name">
                        <p>{userName}</p>
                        <p>{userRole}</p>
                    </div>

                    <button
                        className="navbar__profile__logout"
                        onClick={logoutHandler}
                    >
                        Выйти
                    </button>
                </div>
            </div>
        </div>
    );
};

export default Navbar;
