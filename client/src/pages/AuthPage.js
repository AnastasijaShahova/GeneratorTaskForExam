import { useContext, useState } from "react";
import { AuthContext } from "../context/AuthContext";
import { useHttp } from "../hooks/http.hook";
import "../styles/AuthPage.scss";

const AuthPage = () => {
    const [email, setEmail] = useState("");
    const [password, setPassword] = useState("");

    const auth = useContext(AuthContext);
    const { request } = useHttp(auth.setModal);

    const login = async () => {
        try {
            const data = await request(
                "http://127.0.0.1:3001/auth/login?page=1",
                "POST",
                {
                    email,
                    password,
                },
            );
            if (data.status) {
                auth.login(data.name, data.userId, "ученик");
            }
        } catch (err) {
            console.log("Login error", err);
        }
    };

    return (
        <div className="authpage">
            <div className="authpage__content">
                <div className="authpage__content__authimg">
                    <div className="authpage__content__authimg__img"></div>
                </div>
                <div className="authpage__content__info">
                    <div className="authpage__content__info__title">
                        <h1>Task Generator</h1>
                        <h4>Готов решать?</h4>
                    </div>
                    <div className="authpage__content__info__inputs">
                        <h4>Log in to Your Account</h4>
                        <div className="input-field col s6">
                            <i className="material-icons prefix">
                                account_circle
                            </i>
                            <input
                                placeholder="Email"
                                value={email}
                                onChange={(e) => setEmail(e.target.value)}
                            />
                        </div>
                        <div className="input-field col s6">
                            <i className="material-icons prefix">https</i>
                            <input
                                placeholder="Password"
                                value={password}
                                onChange={(e) => setPassword(e.target.value)}
                            />
                        </div>
                        <div className="button_field col s6">
                            <button onClick={login}>Войти</button>
                        </div>
                    </div>
                </div>
            </div>
            <div className="authpage__footer">
                <div className="authpage__footer__item">
                    <p>Выбирай задания и составляй из них варианты</p>
                </div>
                <div className="authpage__footer__item">
                    <p>Сохраняй свои результаты и смотри статистику</p>
                </div>
                <div className="authpage__footer__item">
                    <p>Генерация только уникальных заданий</p>
                </div>

                <div className="authpage__footer__item">
                    <p>Никакой рекламы и отвлекающих сообщений</p>
                </div>
            </div>
        </div>
    );
};

export default AuthPage;
