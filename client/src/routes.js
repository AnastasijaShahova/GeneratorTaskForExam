import React from "react";
import { Routes, Route, Navigate } from "react-router-dom";
import AuthPage from "./pages/AuthPage";
import QuestionsPage from "./pages/QuestionsPage";
import VariantsPage from "./pages/VariantsPage";

export const useRoutes = (isAuth) => {
    if (isAuth) {
        return (
            <Routes>
            <Route path="/variants" element={<VariantsPage />} />
            <Route exact path="/variants/variant" element={<QuestionsPage />} />
            <Route path="*" element={<Navigate to="/variants" />} />
        </Routes>

        );
    } else {
        return (
            <Routes>
                 <Route path="/login" element={<AuthPage />} exact />
                 <Route path="*" element={<Navigate to="/login" />} />
            </Routes>
        );
    }
};
