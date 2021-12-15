import { Component } from "react";
import "../styles/AuthPage.scss";

export class AuthPage extends Component {
    render() {
        return (
            <div className="authpage">
                <div className="authpage__content">
                    <p>For teachers</p>
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
                                <input id="icon_prefix2" />
                                <label for="icon_prefix2">Email</label>
                            </div>
                            <div className="input-field col s6">
                                <i className="material-icons prefix">https</i>
                                <input id="icon_prefix2" />
                                <label for="icon_prefix2">Password</label>
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
                        <p>Что-то еще</p>
                    </div>
                </div>
            </div>
        );
    }
}

export default AuthPage;
