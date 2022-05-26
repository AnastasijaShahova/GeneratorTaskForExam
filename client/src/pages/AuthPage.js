import { useContext } from "react";
import { AuthContext } from "../context/AuthContext";
import { useHttp } from "../hooks/http.hook";
import { useForm } from "react-hook-form";
import authImg from "../images/authImg.jpg";
import "../styles/AuthPage.scss";
import validator from "validator";

const AuthPage = () => {
    const {
        register,
        formState: { errors },
        handleSubmit,
        reset,
    } = useForm({
        mode: "onBlur",
    });

    const { login } = useContext(AuthContext);
    const { request } = useHttp();

    const onSubmit = async ({ email, password }) => {
        try {
            const data = await request(
                process.env.REACT_APP_SERVER_URL + "/auth/login?page=1",
                "POST",
                {
                    email,
                    password,
                },
            );
            if (data.status) {
                login(data.fio, data.userId, "ученик");
            }
        } catch (e) {
            console.log("AutPage error", e);
        }
        reset();
    };

    return (
        <div className="authpage">
            <div className="autpage__img">
                <img width="379" height="379" src={authImg} />
            </div>
            <div className="authpage__content">
                <div className="authpage__content__title">
                    <h1>Task Generator</h1>
                    <h4>Готов решать?</h4>
                </div>
                <div className="authpage__content__form">
                    <div></div>

                    <form onSubmit={handleSubmit(onSubmit)}>
                        <h4>Log in to Your Account</h4>
                        <div className="authpage__content__form__input_container">
                            <div className="authpage__content__form__input_icon">
                                <i className="material-icons">account_circle</i>
                            </div>

                            <input
                                placeholder="Email"
                                {...register("email", {
                                    required: "Поле обязательно к заполнению",
                                    validate: (email) =>
                                        validator.isEmail(email),
                                })}
                            />
                        </div>
                        {errors?.email && (
                            <p className="error_message">
                                {errors?.email?.message || "Некорректный email"}
                            </p>
                        )}

                        <div className="authpage__content__form__input_container">
                            <div className="authpage__content__form__input_icon">
                                <i className="material-icons">https</i>
                            </div>
                            <input
                                placeholder="Password"
                                type={"password"}
                                {...register("password", {
                                    required: "Поле обязательно к заполнению",
                                    minLength: {
                                        value: 6,
                                        message: "Минимальная длина пароля: 6",
                                    },
                                })}
                            />
                        </div>
                        {errors?.password && (
                            <p className="error_message">
                                {errors?.password?.message ||
                                    "Некорректный пароль"}
                            </p>
                        )}
                        <div className="authpage__content__form__submit">
                            <div></div>
                            <input type="submit" value="Log In" />
                        </div>
                    </form>
                </div>
            </div>
        </div>
    );
};

export default AuthPage;
