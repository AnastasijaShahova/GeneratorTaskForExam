import "../index.css";

export const AuthPage = () => {
    return (
        <div className="row">
            <h2 className="center-align" style={{ color: "#512da8" }}>
                Погнали порешаем
            </h2>
            <div className="block imgBlockContent s12">
                <div className="row blur">
                    <div className="col s5 setCenter">
                        <p>
                            <i className="material-icons">check</i> Готовься к
                            ЕГЭ бесплатно
                        </p>
                        <p>
                            <i className="material-icons">check</i>Есть
                            отдельные варианты и отдельные задания
                        </p>
                        <p>
                            <i className="material-icons">check</i>Еще какой-то
                            плюсик
                        </p>
                    </div>
                    <div className="col s7 setCenter">
                        <div className="row">
                            <div className="input-field col s10">
                                <input
                                    id="email"
                                    type="email"
                                    className="validate green-input"
                                />
                                <label for="email">Email</label>
                            </div>
                        </div>
                        <div className="row">
                            <div className="input-field col s10">
                                <input
                                    id="password"
                                    type="password"
                                    className="validate green-input"
                                />
                                <label for="password">Password</label>
                            </div>
                        </div>

                        <div className="row authBtn">
                            <a className="waves-effect waves-light btn-large left-align">
                                Регистрация
                            </a>
                            <a className="waves-effect waves-light btn-large right-align">
                                Войти
                            </a>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    );
};
