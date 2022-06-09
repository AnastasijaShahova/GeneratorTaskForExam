import React from "react";
import { Routes, Route, Navigate } from "react-router-dom";
import AuthPage from "./pages/AuthPage";
import ExamStatisticPage from "./pages/ExamStatisticPage";
import GeneralRatingPage from "./pages/GeneralRatingPage";
import JournalPage from "./pages/JournalPage";
import QuestionsPage from "./pages/QuestionsPage";
import StatisticPage from "./pages/StatisticPage";
import StudentProfilePage from "./pages/StudentProfilePage";
import TeacherPage from "./pages/TeacherPage";
import TopicStatistikPage from "./pages/TopicStatisticPage";
import VariantsPage from "./pages/VariantsPage";

export const useRoutes = (isAuth, role) => {
    if (isAuth) {
        if (role === "ученик") {
            return (
                <Routes>
                    <Route path="/variants" element={<VariantsPage />} />
                    <Route
                        exact
                        path="/variants/variant"
                        element={<QuestionsPage />}
                    />
                    <Route path="/statistic" element={<StatisticPage />} />
                    <Route
                        path="/general-rating"
                        element={<GeneralRatingPage />}
                    />
                    <Route
                        path="/topic-statistic"
                        element={<TopicStatistikPage />}
                    />
                    <Route
                        path="/exam-statistic"
                        element={<ExamStatisticPage />}
                    />

                    <Route path="*" element={<Navigate to="/variants" />} />
                </Routes>
            );
        } else if (role === "учитель") {
            return (
                <Routes>
                    <Route path="/teacher" element={<TeacherPage />} />
                    <Route path="/teacher/journal" element={<JournalPage />} />
                    <Route
                        path="/teacher/student-profile"
                        element={<StudentProfilePage />}
                    />

                    <Route path="*" element={<Navigate to="/teacher" />} />
                </Routes>
            );
        }
    } else {
        return (
            <Routes>
                <Route path="/login" element={<AuthPage />} exact />
                <Route path="*" element={<Navigate to="/login" />} />
            </Routes>
        );
    }
};
